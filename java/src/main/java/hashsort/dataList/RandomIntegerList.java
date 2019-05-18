package hashsort.dataList;

import java.util.Random;

public class RandomIntegerList extends ElementDataList {

    public RandomIntegerList() { }

    public RandomIntegerList(int arraySize, int maxValue) {
        this.data = new Integer[arraySize];
        Random rand = new Random();
        int lastValue = 0;
        for(int i = 0; i < arraySize ; i++) {
            int value = rand.nextInt(maxValue);
            while(lastValue <= rand.nextInt(maxValue)) {
                value = rand.nextInt(maxValue);
                lastValue = value;
            }
            this.data[i] = value;
        }
    }

}
