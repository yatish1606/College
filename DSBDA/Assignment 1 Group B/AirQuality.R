# Air Quality
# Yatish Kelkar TE IT 8001

airQuality <- data.frame(airquality)

airQuality$Ozone[is.na(airQuality$Ozone)] <- mean(airQuality$Ozone, na.rm = TRUE)