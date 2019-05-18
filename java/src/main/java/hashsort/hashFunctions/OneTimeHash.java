package hashsort.hashFunctions;

import hashsort.dataList.ElementDataList;

public class OneTimeHash implements HashFunction {

    @Override
    public String getSignature(ElementDataList dataList) {
        long hash = 0L;
        Object elm = dataList.getNextElementData();
        while(elm != null) {
            hash += (Integer)elm;
            hash += (hash << 10);
            hash ^= (hash >> 6);

            elm = dataList.getNextElementData();
        }

        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);

        return String.valueOf(hash);
    }
}
