export const availableCurrencies = [
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

export const hotelsList = [
    {
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
        ],
        prices : [
            {
                name : 'Booking.com',
                price : '21,050',
            },
            {
                name : 'MakeMyTrip',
                price : '23,250',
            },
            {
                name : 'Agoda',
                price : '25,920',
            },
        ]
    }
]