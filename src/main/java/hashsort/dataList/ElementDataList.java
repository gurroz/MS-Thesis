package hashsort.dataList;

public abstract class ElementDataList {

    protected Integer[] data;
    protected int index = 0;

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

    public Object[] toArray() {
        return data.clone();
    }

    public void setData(Integer[] data){
        this.data = data.clone();
    }

    public ElementDataList copy(){
        RandomIntegerList newList = new RandomIntegerList();
        newList.setData(this.data);
        return newList;
    }
}
