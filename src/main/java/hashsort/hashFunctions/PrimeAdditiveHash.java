package hashsort.hashFunctions;

import hashsort.dataList.ElementDataList;

public class PrimeAdditiveHash implements HashFunction {

    @Override
    public String getSignature(ElementDataList dataList) {
        long hash = 17L;
        Object elm = dataList.getNextElementData();
        while(elm != null) {
            hash = hash * 19 + (Integer)elm;
            elm = dataList.getNextElementData();
        }

        return String.valueOf(hash);
    }
}
