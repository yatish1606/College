# Air Quality
# Yatish Kelkar TE IT 8001

data("airquality")
airQuality <- airquality

summary(airQuality)

# replace NA values with mean
airQuality$Ozone[is.na(airQuality$Ozone)] <- mean(airQuality$Ozone, na.rm = TRUE)
airQuality$Solar.R[is.na(airQuality$Solar.R)] <- mean(airQuality$Solar.R, na.rm = TRUE)

summary(airQuality)

# data integration

subset1 <- airQuality[1:10, c(2,3)]
subset2 <- airQuality[1:10, c(4,5)]   
cbind(subset1, subset2)

s1 <- airQuality[1:5, c(2,3,4,5)]
s2 <- airQuality[6:10, c(2,3,4,5)]
rbind(s1,s2)

# data transformation

copy <- airQuality
copy$Month <- month.abb[copy$Month]

# add a variable to check if solar value is dangerous

# airQuality$Dangerous <- airQuality$Solar.R > 110


# model building

plot(y~x)

#shuffle
set.seed(12345678)
airQuality <- airQuality[sample(nrow(airQuality)),]

splitPoint <- nrow(airQuality)*0.75
train <- airQuality[1:splitPoint,]
test <- airQuality[(splitPoint + 1):nrow(airQuality),]

train
test

model <- lm(Ozone~Solar.R, data = train)
model
abline(model, col="green", lwd = 5)

prediction <- predict(model, test)
prediction
