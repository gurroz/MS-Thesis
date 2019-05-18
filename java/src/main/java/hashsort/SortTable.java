package hashsort;

import hashsort.dataResult.DataResult;

import java.util.HashMap;
import java.util.Map;

public class SortTable {
    private Map<String, DataResult> hashes;

    public SortTable(){
        hashes = new HashMap<>();
    }

    public void put(String hash, DataResult result) {
        this.hashes.put(hash, result);
    }

    public DataResult get(String hash) {
        return this.hashes.get(hash);
    }

    public int getSize() {
        return this.hashes.size();
    }
}
