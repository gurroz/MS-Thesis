package hashsort.dataList;

import hashsort.Configuration;
import hashsort.dataGenerators.DataGenerator;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class ListOfLists implements DataList{
    private int size;
    private List<ElementDataList> elements;
    private List<ElementDataList> originalElements;
    private int index = 0;
    private DataSparcityEnum sparcity;
    private int arrayLength;
    private int maxValue;
    private DataDistributionEnum ditribution;
    private DataOrderEnum order;

    public ListOfLists(Configuration configuration) {
        this.size = configuration.getListSize();
        this.elements = new ArrayList<>(size);
        this.sparcity = configuration.getSparcity();
        this.arrayLength = configuration.getListSize();
        this.maxValue = configuration.getMaxElementValue();
        this.order = configuration.getOrder();
        this.ditribution = configuration.getDistribution();
    }

    public void populate(DataGenerator generator) {
        long uniqueElemensts = 1;
        switch (this.sparcity) {
            case TWENTY_FIVE:
                uniqueElemensts = Math.round(0.25 * this.size);
                break;
            case FIFTY:
                uniqueElemensts = Math.round(0.5 * this.size);
                break;
            case SEVENTY_FIVE:
                uniqueElemensts = Math.round(0.75 * this.size);
                break;
            case RANDOM:
                uniqueElemensts = Math.round(1 * this.size);
                break;
        }

        this.originalElements = new ArrayList<>((int)uniqueElemensts);


        ElementDataList dataList = generator.getList(arrayLength, maxValue, order);
        for(int i = 0; i < uniqueElemensts ; i++) {
            this.originalElements.add(dataList);
            dataList = generator.getList(arrayLength, maxValue, order);
        }

        switch(this.ditribution) {
            case NORMAL:
                Random random = new Random();
                int average = Math.round(uniqueElemensts/2);
                int stdDev = Math.round(uniqueElemensts/4);

                for(int i = 0; i < this.size; i++) {
                    long elementIndex = Math.max(0, Math.min(uniqueElemensts -1, (int)( average +  random.nextGaussian() * stdDev)));
                    if( elementIndex == 0 || elementIndex == (uniqueElemensts -1)) {
                        elementIndex = Math.max(0, Math.min(uniqueElemensts -1, (int)( average +  random.nextGaussian() * stdDev)));
                    }
                    this.elements.add(originalElements.get((int)elementIndex).copy());
                }
                break;
            case UNIFORM:
            default:
                for(int i = 0; i < this.size; i++) {
                    for(ElementDataList data : originalElements) {
                        this.elements.add(data.copy());
                    }
                }
                break;

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

}
