package hashsort.dataList;

import hashsort.Configuration;
import hashsort.data_generators.DataGenerator;

import java.util.ArrayList;
import java.util.List;

public class SmallList implements DataList{
    private int size;
    private List<ElementDataList> elements;
    private int index = 0;
    private DataSparcityEnum sparcity;
    private int arrayLength;
    private int maxValue;

    public SmallList(Configuration configuration) {
        this.size = configuration.getListSize();
        this.elements = new ArrayList<>(size);
        this.sparcity = configuration.getSparcity();
        this.arrayLength = configuration.getListSize();
        this.maxValue = configuration.getMaxElementValue();
    }

    public void populate(DataGenerator generator) {
        double percentage = 1;
        switch (this.sparcity) {
            case TWENTY_FIVE:
                percentage = 0.25 * this.size;
                break;
            case FIFTY:
                percentage = 0.5 * this.size;
                break;
            case SEVENTY_FIVE:
                percentage = 0.75 * this.size;
                break;
            case RANDOM:
                percentage = 1 * this.size;
                break;
        }

        ElementDataList dataList = generator.getRandomList(arrayLength, maxValue);
        int uniqueItems = 1;
        for(int i = 0; i < this.size ; i++) {
            this.elements.add(dataList.copy());
            if(uniqueItems < percentage) {
                dataList = generator.getRandomList(arrayLength, maxValue);
                uniqueItems++;
            }
        }
    }

    public ElementDataList getNextData() {
        ElementDataList element;
        if(this.index < this.size) {
            element = this.elements.get(index);
            index++;
        } else {
            this.index = 0;
            element = null;
        }
        return element;
    }

    @Override
    public List<ElementDataList> getAllData() {
        return this.elements;
    }

}
