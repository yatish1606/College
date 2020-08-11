const b = document.querySelector('.book')


window.onload = function runOnLoad() {

    // const a = JSON.parse(localStorage.getItem('hotelData'))
    // console.log(a)
    // a.prices.forEach(i => b.innerHTML += `<h1>${i.name}</h1>`)
    console.log(JSON.parse(localStorage.getItem('hotelData')))
}