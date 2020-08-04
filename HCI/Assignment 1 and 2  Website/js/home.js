const $header = document.querySelector('.home-header')
const $searchBar = document.querySelector('.home-searchbar')
const $menu = document.querySelector('.menu')
const $logo = document.querySelector('.home-logo-content')
const $logoImage = document.getElementById('logo')
const $languageSelectImage = document.getElementById('language-select-image')
const $languageDropdownArrow = document.getElementById('language-select')
//const $languageSelect = document.getElementById('language-select')

$menu.classList.add("home-searchbar-menu-visible")
$searchBar.classList.add("home-searchbar-inside");


window.onload = function runOnLoad() {
    $searchBar.innerHTML = document.getElementById("searchbar-inside").innerHTML
    console.log('Homepage Loaded') 
    $logoImage.src = "images/icons/logo_white.png"
    $languageSelectImage.src = "images/icons/language_white.png"
    $languageDropdownArrow.src = "images/icons/down_white.png"
}


//window.scroll(0,1)

// availableCurrencies.forEach(language => {
//     let newOption = new Option('Option Text','Option Value');
//     $languageSelect.add(newOption, undefined)
// })

// for(index in example_array) {
//     select.options[select.options.length] = new Option(example_array[index], index);
// }


window.addEventListener('scroll', event => {
    
    if(this.scrollY > 0){
        $header.classList.add('white-bg')
        $header.classList.remove('no-bg')
    } else {
        $header.classList.add('no-bg')
        $header.classList.remove('white-bg')
    }

    if(this.scrollY > 0){
        $searchBar.classList.add("home-searchbar-outside");
        $logo.classList.add("change");
        // $header.classList.add("fadeIn");
        $header.classList.remove("fadeOut");
        $searchBar.classList.remove("home-searchbar-inside");
        $menu.classList.add("home-searchbar-menu-not-visible")
        $menu.classList.remove("home-searchbar-menu-visible")
        $languageDropdownArrow.classList.add("change")
    } else {
        $searchBar.classList.add("home-searchbar-inside");
        $searchBar.classList.add("fadeIn");
        $searchBar.classList.remove("home-searchbar-outside");
        $menu.classList.add("home-searchbar-menu-visible");
        $menu.classList.remove("home-searchbar-menu-not-visible");
        $logo.classList.remove("change");
        $languageDropdownArrow.classList.remove("change")
    }

    if($searchBar.classList.contains("home-searchbar-inside")){
        $searchBar.innerHTML = document.getElementById("searchbar-inside").innerHTML
    } else if($searchBar.classList.contains("home-searchbar-outside")) {
        $searchBar.innerHTML = document.getElementById("searchbar-outside").innerHTML
    }

    if($logo.classList.contains("change")){
        $logoImage.src = "images/icons/logo_salmon.png"
        $languageSelectImage.src = "images/icons/language.png"
    } else {
        $logoImage.src = "images/icons/logo_white.png"
        $languageSelectImage.src = "images/icons/language_white.png"
    }
})

