const availableCurrencies = [
    {
        symbol : '$',
        name : 'USD',
    },
    {
        symbol : '€',
        name : 'EUR',
    },
    {
        symbol : '₹',
        name : 'INR',
    },
    {
        symbol : '£',
        name : 'GBP',
    },
    {
        symbol : '¥',
        name : 'YEN',
    },
]

const hotelsList = [
    {
        id:0,
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
                image : '../images/icons/wifi_black.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned_black.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/parking_black.png',
                description : 'Parking'
            },
            {
                image : '../images/icons/pool_black.png',
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
        id:1,
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
                image : '../images/icons/wifi_black.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned_black.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/gym_black.png',
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
        id:2,
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
                image : '../images/icons/wifi_black.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned_black.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/pool_black.png',
                description : 'Swimming pool'
            },
            {
                image : '../images/icons/gym_black.png',
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
        id:3,
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
                image : '../images/icons/wifi_black.png',
                description : 'WiFi'
            },
            {
                image : '../images/icons/air_conditioned_black.png',
                description : 'Air Conditioned'
            },
            {
                image : '../images/icons/gym_black.png',
                description : 'Gym'
            },
            {
                image : '../images/icons/fork_black.png',
                description : 'Restaurant'
            },
            {
                image : '../images/icons/pool_black.png',
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

window.onload = function runOnLoad() {
    
    localStorage.setItem('hotelList', JSON.stringify(hotelsList))
    console.log(JSON.parse(localStorage.getItem('hotelList')))
}

