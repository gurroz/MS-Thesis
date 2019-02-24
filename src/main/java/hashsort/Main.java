package hashsort;

import hashsort.dataList.DataDistributionEnum;
import hashsort.dataList.DataList;
import hashsort.dataList.DataSparcityEnum;
import hashsort.dataList.SmallList;
import hashsort.data_generators.IntegerListGenerator;
import hashsort.hash_functions.AdditiveHash;
import hashsort.hash_functions.PrimeAdditiveHash;
import hashsort.hash_functions.ShiftXorHash;
import hashsort.sortAlgorithm.InsertionSort;
import hashsort.sortAlgorithm.MergeSort;

public class Main {

    static final int RUN_NUM = 10;
    public static void main(String [] args) {

        // Que contar
        // Generacion de datos
        // Generacion de signature
        // Sorting
        // Proceso completo individual
        // Proceso completo total
        // Proceso sin hash
        // Cantidad de Hit de cache
        // Cantidad de datos

        // list size: 64, 128, 256, 512
        // Sparcity: 25, 50, 75 , 100
        // Distribution: Normal, Flat, Skewed
        // Hash: Additive, Prime : ShiftXor
        // Max value: 1000 Is this the same as distribution??
        // Sort: Insertion merge

        Configuration conf = new Configuration(10000, 512, DataSparcityEnum.TWENTY_FIVE,
                DataDistributionEnum.FLAT, new ShiftXorHash(), 1000, new MergeSort());


        executeTestWithConf(conf, "PrimeAdditiveHashMerge_");


//        Configuration confMergeSort = new Configuration(1000000, 512, DataSparcityEnum.TWENTY_FIVE,
//                DataDistributionEnum.FLAT, new AdditiveHash(), 1000, new InsertionSort());
//
//        executeSortTest(confMergeSort);
    }

    static void executeTestWithConf(Configuration conf, String title) {
        ReportGenerator report = new ReportGenerator(title + conf.getListSize());

        for(int i = 1; i <= RUN_NUM; i++) {
            DataList data = new SmallList(conf);
            data.populate(new IntegerListGenerator());

            executeTest(data, conf, report, i);
        }

        report.flush();
    }


    static void executeTest(DataList data, Configuration conf, ReportGenerator report, int i) {
        TestRun test1 = new TestRun(report, conf, data, i);
        test1.run();
    }

    static void executeSortTest(Configuration conf) {
        ReportGenerator report = new ReportGenerator("SortingComparisonIns512");

        for(int i = 1; i <= RUN_NUM; i++) {
            DataList data = new SmallList(conf);
            data.populate(new IntegerListGenerator());

            SortingTestRun test1 = new SortingTestRun(report, conf, data);
            test1.run(i);
        }

        report.flushSortTemplate();
    }
}
