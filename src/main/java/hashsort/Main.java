package hashsort;

public class Main {

//
    static {
        TestRunner runner = new TestRunner();
        for (int i = 0; i < 1001; i++) {
            runner.runTest();
        }
    }

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

//        Configuration conf = new Configuration(10000, 512, DataSparcityEnum.TWENTY_FIVE,
//                DataDistributionEnum.UNIFORM, new ShiftXorHash(), 1000, new MergeSort());
//
//
//        executeTestWithConf(conf, "PrimeAdditiveHashMerge_");


        TestRunner runner = new TestRunner();
        runner.runTest();

    }
}
