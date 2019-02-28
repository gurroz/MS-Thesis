package hashsort.dataList;

import hashsort.dataGenerators.DataGenerator;

public interface DataList {
    void populate(DataGenerator generator);
    ElementDataList getNextData();
}
