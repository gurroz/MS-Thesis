//
//  MemoryUtil.cpp
//  HashSort
//
//  Created by Gonzalo Urroz on 12/5/19.
//  Copyright © 2019 Gonzalo Urroz. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

using namespace std;

class MemoryUtil {
public:
//    static int getVirtualMemoryProcess() {
//        cout << "Getting the memory" << endl;
//        struct task_basic_info t_info;
//        mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
//
//        if (KERN_SUCCESS != task_info(mach_task_self(),
//                                      TASK_BASIC_INFO, (task_info_t)&t_info,
//                                      &t_info_count)) {
//            cout << "Virtual " <<  t_info.virtual_size << endl;
//            return 0;
//        } else {
//            cout << "Error memory " << endl;
//        }
//        cout << "Finishing " << endl;
//
//        return 1;
//    }
    
    struct MemoryStat {
        struct {
            unsigned long long    total;
            unsigned long long    avail;
            unsigned long long    used;
            unsigned long long  app;
        } virt;
        struct {
            unsigned long long  total;
            unsigned long long  avail;
            unsigned long long  used;
            unsigned long long  app;
        } phys;
    };
    
    static int getVirtualMemoryProcess() {
        MemoryStat memoryStat = MemoryStat();
//        cout << "Getting the memory" << endl;
        long totalMemory = 0;
        if(getMemoryStats(&memoryStat)) {
            totalMemory =  memoryStat.phys.app / 1000;
        };
        return totalMemory;
    }

private:
    static int getMemoryStats(MemoryStat* memoryStat) {
        // Get Virtual Memory Stats
        xsw_usage vmusage = {0};
        size_t size = sizeof(vmusage);
        if( sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0) != 0 )
        {
            return -1;
        }
        // TODO Gotta be a speedier way to copy
        memoryStat->virt.total = vmusage.xsu_total;
        memoryStat->virt.avail = vmusage.xsu_avail;
        memoryStat->virt.used = vmusage.xsu_used;
        
        // Get Physical RAM Stats
        int mib[2];
        mib[0] = CTL_HW;
        mib[1] = HW_MEMSIZE;
        size_t length = sizeof(memoryStat->phys.total);
        sysctl(mib, 2, &memoryStat->phys.total, &length, NULL, 0);
        
        mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
        vm_statistics_data_t vmstat;
        if(KERN_SUCCESS != host_statistics(mach_host_self(), HOST_VM_INFO, (host_info_t)&vmstat, &count)) {
            return -2;
        }
        memoryStat->phys.avail = (int64_t)vmstat.free_count * (int64_t)vmusage.xsu_pagesize;
        memoryStat->phys.used = ((int64_t)vmstat.active_count +
                                 (int64_t)vmstat.inactive_count +
                                 (int64_t)vmstat.wire_count) *  (int64_t)vmusage.xsu_pagesize;
        
        // Get App Memory Stats
        struct task_basic_info t_info;
        mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
        
        if (KERN_SUCCESS != task_info(mach_task_self(),
                                      TASK_BASIC_INFO, (task_info_t)&t_info,
                                      &t_info_count))
        {
            return -3;
        }
        memoryStat->virt.app = t_info.virtual_size;
        memoryStat->phys.app = t_info.resident_size;
        return 0;
    }

};
