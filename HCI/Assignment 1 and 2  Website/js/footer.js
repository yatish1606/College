const $socialMediaBox = document.querySelector('.social-media-icons')

const icons = [
    {
        icon : "../images/icons/instagram.png",
        action : "/",
        name : 'Instagram'
    },
    {
        icon : "../images/icons/youtube.png",
        action : "/",
        name : 'YouTube'
    },
    {
        icon : "../images/icons/facebook.png",
        action : "/",
        name : 'Facebook'
    },
    {
        icon : "../images/icons/linkedin.png",
        action : "/",
        name : 'LinkedIN'
    },
    {
        icon : "../images/icons/whatsapp.png",
        action : "/",
        name : 'WhatsApp'
    },
    {
        icon : "../images/icons/twitter.png",
        action : "/",
        name : 'Twitter'
    },
]

const loadIcons = () => {
    icons.forEach((item, index) => {
        const iconCard = document.createElement('div');

        const content = `
            <div class="social-media-icons-card">
                <img src=${item.icon} class="social-media-icons-image"/>
                <p class="social-media-icons-p">${item.name}</p>
            </div>
        `
        $socialMediaBox.innerHTML += content
    })
}

window.onload = function runOnLoad() {
    loadIcons()
    console.log('Loading icons')
}