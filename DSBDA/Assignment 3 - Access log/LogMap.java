package Logs;

import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.mapreduce.Mapper;

public class LogMap extends Mapper<LongWritable, Text, Text, IntWritable>
{
    public void map(final LongWritable key, final Text value, final Mapper.Context con) throws IOException, InterruptedException {

        final String line = value.toString();

        final StringTokenizer tokenizer = new StringTokenizer(line);

        con.write((Object)new Text(tokenizer.nextToken()), (Object)new IntWritable(1));
    }
}