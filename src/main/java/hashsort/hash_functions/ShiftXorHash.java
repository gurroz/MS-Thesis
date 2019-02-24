package hashsort.hash_functions;

import hashsort.dataList.ElementDataList;

public class ShiftXorHash implements HashFunction {

    @Override
    public String getSignature(ElementDataList dataList) {
        long hash = 0L;
        Object elm = dataList.getNextElementData();
        while(elm != null) {
            hash ^= (hash << 5) + (hash >> 2) + (Integer)elm;

            elm = dataList.getNextElementData();
        }

        return String.valueOf(hash);
    }
}
