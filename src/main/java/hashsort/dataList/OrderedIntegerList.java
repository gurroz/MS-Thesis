package hashsort.dataList;

import java.util.Random;

public class OrderedIntegerList extends ElementDataList {

    public OrderedIntegerList() { }

    public OrderedIntegerList(int arraySize, int maxValue) {
        this.data = new Integer[arraySize];
        Random rand = new Random();
        int randomMultiplier = rand.nextInt(maxValue);
        for(int i = 0; i < arraySize ; i++) {
            this.data[i] = i * randomMultiplier;
        }
    }

}
