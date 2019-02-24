package hashsort.dataList;

import hashsort.data_generators.DataGenerator;

import java.util.List;

public interface DataList {
    void populate(DataGenerator generator);
    ElementDataList getNextData();
    List<ElementDataList> getAllData();
}
