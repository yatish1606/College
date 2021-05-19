package Weather;

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

public class WeatherDriver {

    public static void main(String[] args) throws Exception {

        Configuration con = new Configuration();
        Job job = new Job(con, "Weather");

        String string;

        job.setJarByClass(Weather.WeatherDriver.class);
        job.setMapperClass(Weather.WeatherMapper.class);
        job.setReducerClass(Weather.WeatherReducer.class);

        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(IntWritable.class);

        FileInputFormat.addInputPath(job, new Path(args[1]));
        FileOutputFormat.setOutputPath(job, new Path(args[2]));

        job.waitForCompletion(true);

        FileSystem fs = FileSystem.get(con);
        FileStatus[] status = fs.listStatus(new Path("hdfs://localhost:9000"+args[2]));
        FSDataInputStream fd = fs.open(status[1].getPath());

        string = fd.readLine();

        float max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, temp;
        String minYear = null, maxYear = null;

        while(string != null) {
            String [] tokens = string.split("\t");
            temp = Integer.parseInt(tokens[1]);

            if(temp > max) {
                max = temp;
                maxYear = tokens[0];
                continue;
            }
            if(temp < min) {
                min = temp;
                minYear = tokens[0];
            }
            string = fd.readLine();
        }

        System.out.println("Maximum temperature : " + max/10 + " in the year " + maxYear);
        System.out.println("Minimum temperature : " + min/10 + " in the year " + minYear);
    }
}
