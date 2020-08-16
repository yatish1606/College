//const {hotelsList} = require('../sampleInfo')
const $features = document.getElementsByClassName('feature')

const colors = ['#1094C34a', '#0BB02E3a', '#ED8A0E4a', '#460EED2a', '#0E83ED3a', '#eee', '#EBB0054a', '#0AB88E3a', '#E117082a', '#B0D50B3a']
let selectedHotel = null

Array.from($features).forEach($feature => {
    $feature.style.backgroundColor = colors[Math.floor(Math.random() * colors.length)];
})

const getBG = function() {
    return colors[Math.floor(Math.random() * colors.length)].toString()
}

const bookHotel = function(index) {
    localStorage.setItem('hotelData', JSON.stringify(hotelsList[index]))
    console.log(JSON.parse(localStorage.getItem('hotelData')))
}

const loadHotels = function() {
    
    const $hotelContainer = document.querySelector('.right-box')
    
    JSON.parse(localStorage.getItem('hotelList')).map((hotel, index) => {
        const content = `
        <div class="hotel-card">
            <div class="hotel-image-box">
                <img src="${hotel.image}"/>
            </div>
            <div class="hotel-info-box">
                <h2>${hotel.name}</h2>
                <div class="hotel-rating">
                    <img src="../images/icons/star.png"/>
                    <h2>${hotel.rating}</h2>
                    <p>${hotel.reviewsNumber} reviews</p>
                </div>
                <div class="features">
                    ${hotel.features.map(feature => `
                        <div class="feature" style="background-color:${getBG()};">${feature}</div>
                    `).join('')}
                </div>
                <div class="amenities">
                    ${hotel.amenities.map(amenity => `
                        <div class="amenity">
                            <img src="${amenity.image}"/>
                            <p>${amenity.description}</p>
                        </div>
                    `).join('')} 
                </div>
                <div class="prices">
                ${hotel.prices.map(price => `
                    <div class="price-box">
                        <p>${price.name}</p>
                        <h3>&#8377; ${price.price}</h3>
                    </div>
                    <div class="vertical-separator" style="margin: 0 5px; height: 40px; vertical-align: middle;"></div>
                `).join('')}
                </div>
            </div>
            <div class="vertical-separator gradient" style="background-color: #F1F2F8; width:4px; left:-2px"></div>
            <div class="hotel-price-box">
                <h5>Lowest price</h5>
                <h4>we found for this hotel</h4>
                <div class="parent-div">
                    <h6>${hotel.prices[0].name}</h6>
                </div>         
                <h1>&#8377; ${hotel.prices[0].price}</h1>
                <h3>a night</h3>
                <p>taxes and fees not included</p>
                <button class="book-button" onclick="bookHotel(${index})"><a href="hotelInfo.html" target="_top">Book</a></button>
            </div>
            <div class="top-circle-cut"></div>
            <div class="bottom-circle-cut"></div>
        </div>
        <script>
            
        </script>
        `
            
        $hotelContainer.innerHTML += content
    })
    document.querySelector('.prices').removeChild(document.querySelector('.prices').lastChild.previousSibling)
}

window.onload = function runOnLoad() {
    console.log(JSON.parse(localStorage.getItem('hotelList')))
    loadHotels()
}



