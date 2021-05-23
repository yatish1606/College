# Air Quality
# Yatish Kelkar TE IT 8001

data("airquality")
airQuality <- data.frame(airquality)

# replace NA values with mean
airQuality$Ozone[is.na(airQuality$Ozone)] <- mean(airQuality$Ozone, na.rm = TRUE)
airQuality$Solar.R[is.na(airQuality$Solar.R)] <- mean(airQuality$Solar.R, na.rm = TRUE)

summary(airQuality)

# data integration

subset1 <- airQuality[1:10, c(2,3)]

subset2 <- airQuality[1:10, c(4,5)]   

cbind(subset1, subset2)

# data transformation

copy <- airQuality
copy$Month <- month.abb[copy$month]

# add a variable to check if solar value is dangerous

# airQuality$Dangerous <- airQuality$Solar.R > 110


# model building
normalize <- function(x){
  return (x-min(x))/(max(x)-min(x))
}

airQuality <- normalize(airQuality)

y <- airQuality[, 'Ozone']
x <- airQuality[, 'Solar.R']

model <- lm(y~x)
model
plot(x,y)

prediction <- predict(model, data.frame("x" = 20))
prediction
