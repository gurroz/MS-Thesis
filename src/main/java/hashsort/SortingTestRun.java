package hashsort;

import hashsort.dataList.DataList;
import hashsort.dataList.ElementDataList;
import hashsort.data_result.IntegerListResult;
import hashsort.sortAlgorithm.SortAlgorithm;

public class SortingTestRun {
    private ReportGenerator reportGenerator;
    private SortAlgorithm sortAlgorithm;
    private DataList dataList;

    public SortingTestRun(ReportGenerator reportGenerator, Configuration configuration, DataList dataList){
        this.reportGenerator = reportGenerator;
        this.dataList = dataList;
        this.sortAlgorithm = configuration.getSortAlgorithm();
    }

    public void run(int i) {
        ElementDataList elementList =  dataList.getNextData();
        reportGenerator.beginRecord("Rec_SORTING_" + this.sortAlgorithm.getName());

        while(elementList != null) {
            Object[] unsortedArray = elementList.toArray();
            new IntegerListResult((Integer[]) this.sortAlgorithm.sort(unsortedArray));

            elementList = dataList.getNextData();
        }
        long duration = reportGenerator.endRecord("Rec_SORTING_" + this.sortAlgorithm.getName());
        reportGenerator.addRecordValue(i, duration);
    }

}
