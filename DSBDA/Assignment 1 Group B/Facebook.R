
print('Opening the CSV file')

csvFile <- "F:/College Assignements/DSBDA/Assignment 1 Group B/dataset_Facebook.csv"

facebookData <- read.csv(csvFile, sep = ';')

# merge data

subsetData <- facebookData[1:7, 1:8]
otherSubset <- facebookData[, 1:4]
mergedData <- merge(subsetData, otherSubset, by = "Type")


#rbind and cbind

subset3 <- facebookData[,1:2]
subset4 <- facebookData[,3:4]
colBind <- cbind(subset3, subset4)
colBind

subset5 <- facebookData[1:10, c(1,2,3,4)]
subset6 <- facebookData[11:20, c(1,2,3,4)]
rowBind <- rbind(subset5, subset6)
rowBind


# sorting

sortedByLikes <- facebookData[order(facebookData$like, decreasing = "True"), c(1,2,3,4,17)]
head(sortedByLikes)

# transposing

transpose <- t(subsetData)
View(transpose)

library("reshape")
 
# for every combination of type-category, every other variable
# will add as a third column along with it's value
molten <- melt(facebookData, id = c("Type","Category"))
View(molten)  

# for every kind of type there'll be one record
castData <- cast(molten, fun.aggregate = max)
View(castData)


