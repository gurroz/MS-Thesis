package hashsort.dataList;

import java.util.Random;

public class ElementIntegerList extends ElementDataList {

    private Integer[] data;
    private int index = 0;

    public ElementIntegerList() { }

    public ElementIntegerList(int arraySize, int maxValue) {
        this.data = new Integer[arraySize];
        for(int i = 0; i < arraySize ; i++) {
            Random rand = new Random();
            this.data[i] = rand.nextInt(maxValue);
        }
    }

    @Override
    public Object getNextElementData() {
        Integer elm;
        if(this.index < data.length) {
            elm = data[this.index];
            this.index++;
        } else {
            this.index = 0;
            elm = null;
        }
        return elm;
    }

    @Override
    public Object[] toArray() {
        return data.clone();
    }

    private void setData(Integer[] data){
        this.data = data.clone();
    }

    @Override
    public ElementDataList copy(){
        ElementIntegerList newList = new ElementIntegerList();
        newList.setData(this.data);
        return newList;
    }
}
