package hashsort.data_generators;

import hashsort.dataList.ElementDataList;

public interface DataGenerator {

    ElementDataList getRandomList(int arraySize, int maxValue);
}
