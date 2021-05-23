
print('Opening the CSV file')

csvFile <- "F:/College Assignements/DSBDA/Assignment 1 Group B/dataset_Facebook.csv"

facebookData <- read.csv(csvFile, sep = ';')

if(!facebookData) {
  print("Could not open dataset")
  sys.on.exit(0)
}

subsetData <- facebookData[1:7, 1:8]
head(subsetData)

otherSubset <- facebookData[, 1:4]

mergedData <- merge(subsetData, otherSubset, by = "Type")

sortedByLikes <- facebookData[order(facebookData$like, decreasing = "True"), c(1,2,3,4,17)]
head(sortedByLikes)

transpose <- t(subsetData)
View(transpose)

library("reshape")
 
# for every combination of type-category, every other variable
# will add as a third column along with it's value
molten <- melt(subsetData, id = c("Type","Category"))
View(molten)  


castData <- cast(molten, Type~variable, sum)
View(castData)


