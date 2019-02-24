package hashsort.sortAlgorithm;

public class InsertionSort implements SortAlgorithm{

    @Override
    public String getName() {
        return "InsertionSort";
    }

    public Integer[] sort(Object[] list) {
        Integer value;
        int j;
        for(int i = 1; i < list.length; i++) {
            value = (Integer)list[i];
            j = i-1;

            while (j >= 0 && (Integer)list[j] > value) {
                list[j+1] = list[j];
                j = j-1;
            }
            list[j+1] = value;
        }

        return (Integer[])list;
    }
}
