package hashsort;

import hashsort.dataGenerators.IntegerListGenerator;
import hashsort.dataList.*;
import hashsort.hashFunctions.AdditiveHash;
import hashsort.hashFunctions.PrimeAdditiveHash;
import hashsort.hashFunctions.ShiftXorHash;
import hashsort.sortAlgorithm.InsertionSort;
import hashsort.sortAlgorithm.MergeSort;

public class TestRunner {

    static final int RUN_NUM = 10;
    static final int SIZE = 256;

    public TestRunner(){}

    void runTest() {
        Configuration confPrime = new Configuration(500000, SIZE, DataSparcityEnum.RANDOM,
                DataDistributionEnum.NORMAL, new PrimeAdditiveHash(), 1000, new InsertionSort(), DataOrderEnum.RANDOM);

        Configuration confXor = new Configuration(500000, SIZE, DataSparcityEnum.RANDOM,
                DataDistributionEnum.NORMAL, new ShiftXorHash(), 1000, new InsertionSort(), DataOrderEnum.RANDOM);

        Configuration confAdd = new Configuration(500000, SIZE, DataSparcityEnum.RANDOM,
                DataDistributionEnum.NORMAL, new AdditiveHash(), 1000, new InsertionSort(), DataOrderEnum.RANDOM);


        executeTestWithConf(confPrime, confXor, confAdd, "Prime_100_"+SIZE, "Xor_100_"+SIZE,"Add_100_"+SIZE);
    }

    void executeTestWithConf(Configuration conf1,Configuration conf2, Configuration conf3, String title1, String title2, String title3) {
        ReportGenerator report1 = new ReportGenerator(title1);
        ReportGenerator report2 = new ReportGenerator(title2);
        ReportGenerator report3 = new ReportGenerator(title3);

        for(int i = 1; i <= RUN_NUM; i++) {
            DataList data = new ListOfLists(conf1);
            data.populate(new IntegerListGenerator());

            executeTest(data, conf1, report1, i);
            executeTest(data, conf2, report2, i);
            executeTest(data, conf3, report3, i);
        }

        report1.flush();
        report2.flush();
        report3.flush();
    }

    void executeTest(DataList data, Configuration conf, ReportGenerator report, int i) {
        TestRun test1 = new TestRun(report, conf, data, i);
        test1.run();
    }


    void runTestSort() {
        Configuration confInsertSort1 = new Configuration(500000, SIZE, DataSparcityEnum.RANDOM,
                DataDistributionEnum.NORMAL, new AdditiveHash(), 1000, new InsertionSort(), DataOrderEnum.REVERSE_ORDER);

        Configuration confInsertSort2 = new Configuration(500000, SIZE, DataSparcityEnum.RANDOM,
                DataDistributionEnum.NORMAL, new AdditiveHash(), 1000, new MergeSort(), DataOrderEnum.REVERSE_ORDER);


        executeSortTest(confInsertSort1, confInsertSort2, "Insert_Normal_REVERSE_"+SIZE, "Merge_Normal_REVERSE_"+SIZE);
    }

    void executeSortTest(Configuration conf1, Configuration conf2, String title1, String title2) {
        ReportGenerator report1 = new ReportGenerator(title1);
        ReportGenerator report2 = new ReportGenerator(title2);

        for(int i = 1; i <= RUN_NUM; i++) {
            DataList data = new ListOfLists(conf1);
            data.populate(new IntegerListGenerator());

            SortingTestRun test2 = new SortingTestRun(report2, conf2, data);
            test2.run(i);

            SortingTestRun test1 = new SortingTestRun(report1, conf1, data);
            test1.run(i);
        }

        report1.flushSortTemplate();
        report2.flushSortTemplate();
    }
}
