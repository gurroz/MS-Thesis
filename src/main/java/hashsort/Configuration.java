package hashsort;

import hashsort.dataList.DataDistributionEnum;
import hashsort.dataList.DataOrderEnum;
import hashsort.dataList.DataSparcityEnum;
import hashsort.hashFunctions.HashFunction;
import hashsort.sortAlgorithm.SortAlgorithm;

public class Configuration {

    private int listAmount;
    private int listSize;
    private DataSparcityEnum sparcity;
    private DataDistributionEnum distribution;
    private HashFunction hashFunction;
    private int maxElementValue;
    private SortAlgorithm sortAlgorithm;
    private DataOrderEnum order;

    public Configuration(int listAmount, int listSize, DataSparcityEnum sparcity, DataDistributionEnum distribution,
                         HashFunction hashFunction, int maxElementValue, SortAlgorithm sortAlgorithm, DataOrderEnum order) {
        this.listAmount = listAmount;
        this.listSize = listSize;
        this.sparcity = sparcity;
        this.distribution = distribution;
        this.hashFunction = hashFunction;
        this.maxElementValue = maxElementValue;
        this.sortAlgorithm = sortAlgorithm;
        this.order = order;
    }

    public int getListAmount() {
        return listAmount;
    }

    public void setListAmount(int listAmount) {
        this.listAmount = listAmount;
    }

    public int getListSize() {
        return listSize;
    }

    public void setListSize(int listSize) {
        this.listSize = listSize;
    }

    public DataSparcityEnum getSparcity() {
        return sparcity;
    }

    public void setSparcity(DataSparcityEnum sparcity) {
        this.sparcity = sparcity;
    }

    public DataDistributionEnum getDistribution() {
        return distribution;
    }

    public void setDistribution(DataDistributionEnum distribution) {
        this.distribution = distribution;
    }

    public HashFunction getHashFunction() {
        return hashFunction;
    }

    public void setHashFunction(HashFunction hashFunction) {
        this.hashFunction = hashFunction;
    }

    public int getMaxElementValue() {
        return maxElementValue;
    }

    public void setMaxElementValue(int maxElementValue) {
        this.maxElementValue = maxElementValue;
    }

    public SortAlgorithm getSortAlgorithm() {
        return sortAlgorithm;
    }

    public void setSortAlgorithm(SortAlgorithm sortAlgorithm) {
        this.sortAlgorithm = sortAlgorithm;
    }

    public DataOrderEnum getOrder() {
        return order;
    }

    public void setOrder(DataOrderEnum order) {
        this.order = order;
    }
}
