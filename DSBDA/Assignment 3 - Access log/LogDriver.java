package Logs;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FileStatus;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class LogDriver {

    public static void main(String[] args) throws Exception {

        Configuration con = new Configuration();
        Job job = new Job(con, "Log count");

        job.setJarByClass(Logs.LogDriver.class);
        job.setMapperClass(Logs.LogMap.class);
        job.setReducerClass(Logs.LogReduce.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);

        FileInputFormat.addInputPath(job, new Path(args[1]));
        FileOutputFormat.setOutputPath(job, new Path(args[2]));

        job.waitForCompletion(true);

        FileSystem fs = FileSystem.get(con);
        FileStatus[] status = fs.listStatus(new Path("hdfs://localhost:9000"+args[2]));
        FSDataInputStream fd = fs.open(status[1].getPath());


        String string = null;
        string = fd.readLine();

        float max = -9999, count;
        String maxIP = null;

        while(string != null) {
            String [] tokens = string.split("\t");
            count = Integer.parseInt(tokens[1]);

            if(count > max) {
                max = count;
                maxIP = tokens[0];
            }

            string = fd.readLine();
        }
        System.out.println("The IP with most logs is " + maxIP + " with " + Math.round(max) + " number of logs");
    }
}