package hashsort.dataGenerators;

import hashsort.dataList.*;

public class IntegerListGenerator implements DataGenerator{

    @Override
    public ElementDataList getList(int arraySize, int maxValue, DataOrderEnum order) {
        ElementDataList resp = null;
        switch (order) {
            case ORDERED:
                resp =  new OrderedIntegerList(arraySize, maxValue);
                break;
            case REVERSE_ORDER:
                resp =  new ReverseIntegerList(arraySize, maxValue);
                break;
            case RANDOM:
                resp =  new RandomIntegerList(arraySize, maxValue);
                break;
            default:
                resp = new RandomIntegerList(arraySize, maxValue);
            break;
        }

        return resp;

    }
}
