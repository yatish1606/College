
facebookData <- read.csv("F:/College Assignements/DSBDA/Assignment 1 Group B/dataset_Facebook.csv", sep = ";")


library("ggplot2")

# Scatterplot
scatterPlot <- ggplot(facebookData, aes(x = Lifetime.Post.Total.Reach, y = Lifetime.Post.Total.Impressions))+ geom_point(color="salmon")  
scatterPlot


# Barplot
barPlot <- ggplot(facebookData, aes(x = Type)) + geom_bar(color="blue", fill="blue")  
barPlot

# pie chart
pieChart <- pie(table(facebookData$Type), labels = c("Link","Photo","Status","Video"))
pieChart

# Lineplot
linePlot <- ggplot(facebookData, aes(x = Lifetime.Post.Total.Reach, y = Lifetime.Post.Total.Impressions, color=Type)) + geom_line(color="orange")  
linePlot


# Boxplot
boxPlot <- ggplot(facebookData, aes(x = Type, y = like)) + geom_boxplot(color="blue")  
boxPlot


data("airquality")

airquality$Ozone[is.na(airquality$Ozone)] <- mean(airquality$Ozone, na.rm = TRUE)
airquality$Solar.R[is.na(airquality$Solar.R)] <- mean(airquality$Solar.R, na.rm = TRUE)
airQuality$Month <- month.abb[airQuality$Month]
# Scatterplot
scatterPlotAQ <- ggplot(airquality, aes(x = Solar.R, y = Ozone)) + geom_point(color="salmon")  
scatterPlotAQ


# Barplot
barPlotAQ <- ggplot(airquality, aes(x = Ozone)) + geom_bar(fill-"blue", color="blue")  
barPlotAQ

pieChartAQ <- ggplot(airQuality, aes(x="", y=Ozone, fill = Month)) + geom_bar(width = 0.2, stat = "identity") + coord_polar("y", start = 0) + theme_void()
pieChartAQ


# Lineplot
linePlotAQ <- ggplot(airquality, aes(x = Wind, y = Temp)) + geom_line(color="orange")  
linePlotAQ

boxPlotAQ <- ggplot(airQuality, aes(x = Temp, y = Ozone)) + geom_boxplot(color="blue")  
boxPlotAQ
