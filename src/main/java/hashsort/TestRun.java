package hashsort;

import hashsort.dataList.DataList;
import hashsort.dataList.ElementDataList;
import hashsort.data_result.DataResult;
import hashsort.data_result.IntegerListResult;
import hashsort.hash_functions.HashFunction;
import hashsort.sortAlgorithm.SortAlgorithm;

public class TestRun {
    private ReportGenerator reportGenerator;
    private SortTable sortTable;
    private DataList dataList;
    private int runNumber;
    private Configuration configuration;
    private HashFunction hashFunction;
    private SortAlgorithm sortAlgorithm;


    public TestRun(ReportGenerator reportGenerator, Configuration configuration, DataList dataList, int runNum){
        this.reportGenerator = reportGenerator;
        sortTable = new SortTable();
        this.configuration = configuration;
        this.dataList = dataList;
        runNumber = runNum;
        this.hashFunction = configuration.getHashFunction();
        this.sortAlgorithm = configuration.getSortAlgorithm();
    }

    public void run() {

        // hash only
        // fix Colitions
        controlRun();
        hashRun();
        hashSortRun();
        colitionRun();
    }

    private void controlRun() {
        ElementDataList elementList =  dataList.getNextData();
        reportGenerator.beginRecord("Rec_"+runNumber+"_SORTING");

        while(elementList != null) {
            Object[] unsortedArray = elementList.toArray();
            new IntegerListResult((Integer[]) this.sortAlgorithm.sort(unsortedArray));

            elementList = dataList.getNextData();
        }
        long duration = reportGenerator.endRecord("Rec_"+runNumber+"_SORTING");
        reportGenerator.addRecordValue(runNumber, duration);
    }

    private void hashRun() {
        ElementDataList elementList =  dataList.getNextData();
        reportGenerator.beginRecord("Rec_"+runNumber+"_HASH_SIGNATURE");

        while(elementList != null) {
            hashFunction.getSignature(elementList);
            elementList = dataList.getNextData();
        }
        long duration = reportGenerator.endRecord("Rec_"+runNumber+"_HASH_SIGNATURE");
        reportGenerator.addRecordValue(runNumber, duration);
    }

    private void hashSortRun() {
        ElementDataList elementList =  dataList.getNextData();
        reportGenerator.beginRecord("Rec_"+runNumber+"_HASH_SORTING");

        long cacheHit = 0L;
        while(elementList != null) {
            String signature = hashFunction.getSignature(elementList);

            DataResult result = sortTable.get(signature);
            if(result == null) {
                Object[] unsortedArray = elementList.toArray();

                IntegerListResult sortedArray = new IntegerListResult((Integer[]) this.sortAlgorithm.sort(unsortedArray));
                sortTable.put(signature, sortedArray);
            } else {
                cacheHit++;
            }
            elementList = dataList.getNextData();
        }

        long duration = reportGenerator.endRecord("Rec_"+runNumber+"_HASH_SORTING");
        reportGenerator.addRecordValue(runNumber, duration);
        reportGenerator.addRecordValue(runNumber, Long.valueOf(sortTable.getSize()));
        reportGenerator.addRecordValue(runNumber, cacheHit);
    }

    private void colitionRun() {
        ElementDataList elementList =  dataList.getNextData();
        long colitions = 0L;
        while(elementList != null) {
            String signature = hashFunction.getSignature(elementList);

            DataResult result = sortTable.get(signature);
            if(result != null) {
                Object[] unsortedArray = elementList.toArray();
                IntegerListResult sortedArray = new IntegerListResult((Integer[]) this.sortAlgorithm.sort(unsortedArray));
                if(!sortedArray.isEquals((IntegerListResult)result)) {
                    colitions++;
                }
            }
            elementList = dataList.getNextData();
        }
        reportGenerator.addRecordValue(runNumber, colitions);
    }
}
