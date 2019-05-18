package hashsort.hashFunctions;

import hashsort.dataList.ElementDataList;

public class AdditiveHash implements HashFunction {

    @Override
    public String getSignature(ElementDataList dataList) {
        long sum = 0;
        Object elm = dataList.getNextElementData();
        while(elm != null) {
            sum += (Integer)elm;
            elm = dataList.getNextElementData();
        }

        return String.valueOf(sum);
    }
}
