package hashsort.dataResult;

import java.util.Arrays;
import java.util.StringJoiner;

public class IntegerListResult extends DataResult {

    private Integer[] data;

    public IntegerListResult(Integer[] data){
        this.data = data;
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", IntegerListResult.class.getSimpleName() + "[", "]")
                .add("data=" + Arrays.toString(data))
                .toString();
    }

    public boolean isEquals(IntegerListResult other){
        return java.util.Arrays.equals(this.data,other.data);
    }
}
