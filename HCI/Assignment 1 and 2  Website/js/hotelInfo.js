const b = document.querySelector('.book')
const $overview = document.querySelector('.overview')
const $location = document.querySelector('.location')
const $reviews = document.querySelector('.reviews')
const $faq = document.querySelector('.faq')
const $more = document.querySelector('.more')
const $hotelBar = document.querySelector('.hotel-bar')
const $hotelContentRight = document.querySelector('.hotel-content-right')



const activeStyle = "color: #FF5A5F;border-bottom: 4px solid #FF5A5F;transition: 0.3s;"
const inactiveStyle = "color: #2a2b2b;border-bottom: 4px solid transparent;transition: 0.3s;"


window.onload = function runOnLoad() {

    setStyle($overview)

    const hotelInfo = JSON.parse(localStorage.getItem('hotelData'))
    console.log(hotelInfo)

    const allHotelsInfo = JSON.parse(localStorage.getItem('hotelList'))
    console.log(allHotelsInfo)
    
    const suggestionHotels = allHotelsInfo.filter(hotel => hotel.name !== hotelInfo.name)
    console.log(suggestionHotels)

    $overview.addEventListener('click', function () {
        $overview.style.cssText = activeStyle
        $location.style.cssText = inactiveStyle
        $reviews.style.cssText = inactiveStyle
        $faq.style.cssText = inactiveStyle
        $more.style.cssText = inactiveStyle
        window.scrollTo(0,500)
    })

    
    $location.onclick = function() {
        $location.style.cssText = activeStyle
        $overview.style.cssText = inactiveStyle
        $reviews.style.cssText = inactiveStyle
        $faq.style.cssText = inactiveStyle
        $more.style.cssText = inactiveStyle
        window.scrollTo(0,1010)
    }

    $reviews.addEventListener('click', function () {
        $reviews.style.cssText = activeStyle
        $location.style.cssText = inactiveStyle
        $overview.style.cssText = inactiveStyle
        $faq.style.cssText = inactiveStyle
        $more.style.cssText = inactiveStyle
        window.scrollTo(0,1510)
    })

    $faq.addEventListener('click', function () {
        $faq.style.cssText = activeStyle
        $location.style.cssText = inactiveStyle
        $reviews.style.cssText = inactiveStyle
        $overview.style.cssText = inactiveStyle
        $more.style.cssText = inactiveStyle
    })

    $more.addEventListener('click', function () {
        $more.style.cssText = activeStyle
        $location.style.cssText = inactiveStyle
        $reviews.style.cssText = inactiveStyle
        $faq.style.cssText = inactiveStyle
        $overview.style.cssText = inactiveStyle
    })
}

const options = [$overview,$location,$reviews,$faq,$more]

const setStyle = (node) => {
    node.style.cssText = activeStyle
    options.filter(option => option !== node).forEach(otherNode => otherNode.style.cssText = inactiveStyle)
}

window.addEventListener('scroll', event => {
    
    if(this.scrollY > window.innerHeight - 90){
        $hotelBar.style.cssText = "position: fixed;top:0px; left:0;margin-top:0;padding-top:50px;padding-right:15px"
        $hotelContentRight.style.cssText = "position: fixed;top:100px; right:10%; width:28% "
    } else {
        $hotelBar.style.cssText = "position:none"
        $hotelContentRight.style.cssText = "position: none "
    }
    if(this.scrollY > 500){
        setStyle($overview)
    }
    if(this.scrollY > 1000){
        setStyle($location)
    }
    if(this.scrollY > 1500){
        setStyle($reviews)
    }
    if(this.scrollY > 2000){
        setStyle($faq)
    }
    if(this.scrollY > 2500){
        setStyle($more)
    }
})