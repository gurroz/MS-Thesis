package hashsort.data_generators;

import hashsort.dataList.ElementDataList;
import hashsort.dataList.ElementIntegerList;

public class IntegerListGenerator implements DataGenerator{

    @Override
    public ElementDataList getRandomList(int arraySize, int maxValue) {
        return new ElementIntegerList(arraySize, maxValue);
    }
}
