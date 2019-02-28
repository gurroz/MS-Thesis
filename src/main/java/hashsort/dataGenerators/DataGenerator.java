package hashsort.dataGenerators;

import hashsort.dataList.DataOrderEnum;
import hashsort.dataList.ElementDataList;

public interface DataGenerator {

    ElementDataList getList(int arraySize, int maxValue, DataOrderEnum order);
}
