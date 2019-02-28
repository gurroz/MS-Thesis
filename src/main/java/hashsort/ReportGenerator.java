package hashsort;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class ReportGenerator {

    private Map<String, Long> timeRecords;
    private Map<Integer, List<Long>> records;
    private String title;
    private LocalDate date;

    public ReportGenerator(String title) {
        this.date = LocalDate.now();
        this.timeRecords = new LinkedHashMap<>();
        this.records = new LinkedHashMap<>();
        this.title = title;
    }

    public void beginRecord(String key) {
        long time = System.nanoTime();
        timeRecords.put(key, time);
    }

    public long endRecord(String key) {
        long endTime = System.nanoTime();
        Long startTime = timeRecords.get(key);

        long duration =  0L;
        if(startTime != null) {
            duration =  endTime -startTime;
        }

        long mili = (duration / 1000000L);

        return duration;
    }

    public void addRecordValue(Integer key, long value) {
        List<Long> data = records.get(key);
        if(data == null ) {
            data = new ArrayList<>();
        }
        data.add(value);
        records.put(key, data);
    }


    public void flush() {
        File file = new File("./Report_" + this.title + "_" + date+ ".csv");
        try {
            FileWriter writer = new FileWriter(file);
            writer.write("Report: " + title +"\r\n" );
            writer.write("Date: " + date +"\r\n" );
            writer.write("RECORD,SORTING,HASHING,HASH SORTING,HASH SIZE,HASH HIT,COLITIONS\r\n" );

            for(Map.Entry<Integer, List<Long>> line : records.entrySet()) {
                StringBuilder record = new StringBuilder();
                record.append(line.getKey());
                record.append(",");
                for(Long value: line.getValue()) {
                    record.append(value);
                    record.append(",");
                }
                record.append("\r\n");
                writer.write(record.toString());
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void flushSortTemplate() {
        File file = new File("./Report_" + this.title + "_" + date+ ".csv");
        try {
            FileWriter writer = new FileWriter(file);
            writer.write("Report: " + title +"\r\n" );
            writer.write("Date: " + date +"\r\n" );

            for(Map.Entry<Integer, List<Long>> line : records.entrySet()) {
                StringBuilder record = new StringBuilder();
                record.append(line.getKey());
                record.append(",");
                for(Long value: line.getValue()) {
                    record.append(value);
                    record.append(",");
                }
                record.append("\r\n");
                writer.write(record.toString());
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
