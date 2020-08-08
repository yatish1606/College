const $features = document.getElementsByClassName('feature')

const colors = ['#1094C34a', '#0BB02E3a', '#ED8A0E4a']

Array.from($features).forEach($feature => {
    console.log($feature)
    var random_color = colors[Math.floor(Math.random() * colors.length)];
    $feature.style.backgroundColor = random_color
})

