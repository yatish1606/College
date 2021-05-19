package Logs;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

import java.io.IOException;

public class LogReduce extends Reducer<Text, IntWritable, Text, IntWritable>
{
    public void reduce(final Text word, final Iterable<IntWritable> values, final Context con) throws IOException, InterruptedException {
        int sum = 0;
        for (IntWritable value : values) {
            sum += value.get();
        }
        con.write(word, new IntWritable(sum));
    }
}