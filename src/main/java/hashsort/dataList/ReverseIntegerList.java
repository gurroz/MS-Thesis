package hashsort.dataList;

import java.util.Random;

public class ReverseIntegerList extends ElementDataList {

    public ReverseIntegerList() { }

    public ReverseIntegerList(int arraySize, int maxValue) {
        this.data = new Integer[arraySize];
        Random rand = new Random();
        int randomMultiplier = rand.nextInt(maxValue);

        for(int i = 0; i < arraySize ; i++) {
            this.data[i] = (arraySize - i) * randomMultiplier;
        }
    }

}
