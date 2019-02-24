package hashsort;

import hashsort.dataList.DataDistributionEnum;
import hashsort.dataList.DataSparcityEnum;
import hashsort.hash_functions.HashFunction;
import hashsort.sortAlgorithm.SortAlgorithm;

public class Configuration {

    private int listAmount;
    private int listSize;
    private DataSparcityEnum sparcity;
    private DataDistributionEnum distribution;
    private HashFunction hashFunction;
    private int maxElementValue;
    private SortAlgorithm sortAlgorithm;

    public Configuration(int listAmount, int listSize, DataSparcityEnum sparcity, DataDistributionEnum distribution,
                         HashFunction hashFunction, int maxElementValue, SortAlgorithm sortAlgorithm) {
        this.listAmount = listAmount;
        this.listSize = listSize;
        this.sparcity = sparcity;
        this.distribution = distribution;
        this.hashFunction = hashFunction;
        this.maxElementValue = maxElementValue;
        this.sortAlgorithm = sortAlgorithm;
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
}
