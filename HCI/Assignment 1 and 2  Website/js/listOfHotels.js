//const {hotelsList} = require('../sampleInfo')
const $features = document.getElementsByClassName('feature')

const colors = ['#1094C34a', '#0BB02E3a', '#ED8A0E4a', '#460EED2a', '#0E83ED3a']
let selectedHotel = null
const hotelsList = [
    {
        id:1,
        image : '../images/sheraton_grand.jpg',
        name : 'Sheraton Grand Dubai',
        rating : 4.5,
        reviewsNumber : 1135,
        features : [
            'Good cleanliness',
            'Pets allowed'
        ],
        amenities : [
            {
                image : '../images/icons/wifi.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/parking.png',
                description : 'Parking'
            },
            {
                image : '../images/icons/pool.png',
                description : 'Swimming pool'
            },
        ],
        prices : [
            {
                name : 'Booking.com',
                price : '16,350',
            },
            {
                name : 'MakeMyTrip',
                price : '17,250',
            },
            {
                name : 'Agoda',
                price : '18,020',
            },
        ]
    },
    {
        id:2,
        image : '../images/the_palm.jpg',
        name : 'The Palm',
        rating : 4.8,
        reviewsNumber : 5605,
        features : [
            'Good cleanliness',
            'Pets allowed',
            "Breakfast included"
        ],
        amenities : [
            {
                image : '../images/icons/wifi.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/gym.png',
                description : 'Gym'
            },
        ],
        prices : [
            {
                name : 'Agoda',
                price : '21,050',
            },
            {
                name : 'MakeMyTrip',
                price : '23,250',
            },
            {
                name : 'Booking.com',
                price : '25,920',
            },
        ]
    },
    {
        id:3,
        image : '../images/al_bandar.jpg',
        name : 'Al Bandar Rotana - Dubai Creek',
        rating : 4.4,
        reviewsNumber : 2435,
        features : [
            'Popular',
            "Breakfast included"
        ],
        amenities : [
            {
                image : '../images/icons/wifi.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/pool.png',
                description : 'Swimming pool'
            },
            {
                image : '../images/icons/gym.png',
                description : 'Gym'
            },
        ],
        prices : [
            {
                name : 'MakeMyTrip',
                price : '20,250',
            },
            {
                name : 'Agoda',
                price : '21,050',
            },
            {
                name : 'Booking.com',
                price : '28,120',
            },
        ]
    },
    {
        id:4,
        image : '../images/taj.jpg',
        name : 'Taj Dubai',
        rating : 4.9,
        reviewsNumber : 8435,
        features : [
            'Popular',
            'Pets allowed',
            'Top Rated'
        ],
        amenities : [
            {
                image : '../images/icons/wifi.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/gym.png',
                description : 'Gym'
            },
            {
                image : '../images/icons/fork.png',
                description : 'Restaurant'
            },
            {
                image : '../images/icons/pool.png',
                description : 'Swimming pool'
            },
            
        ],
        prices : [
            {
                name : 'MakeMyTrip',
                price : '24,850',
            },
            {
                name : 'Agoda',
                price : '25,050',
            },
            {
                name : 'Booking.com',
                price : '30,820',
            },
        ]
    }
]

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
    console.log('Loading hotels')
    const $hotelContainer = document.querySelector('.right-box')
    
    hotelsList.map((hotel, index) => {
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
                <button class="book-button" onclick="bookHotel(${index})">Book</button>
            </div>
            <div class="top-circle-cut"></div>
            <div class="bottom-circle-cut"></div>
        </div>
        `
        $hotelContainer.innerHTML += content
    })

    
}

window.onload = function runOnLoad() {
    loadHotels()
    
}

