
facebookData <- read.csv("F:/College Assignements/DSBDA/Assignment 1 Group B/dataset_Facebook.csv", sep = ";")


library("ggplot2")

# Scatterplot
scatterPlot <- ggplot(facebookData, aes(x = Lifetime.Post.Total.Reach, y = Lifetime.Post.Total.Impressions)) + geom_point()  
scatterPlot


# Barplot
barPlot <- ggplot(facebookData, aes(x = Type)) + geom_bar()  
barPlot


# Boxplot
boxPlot <- ggplot(facebookData, aes(x = Type, y = like)) + geom_boxplot()  
boxPlot