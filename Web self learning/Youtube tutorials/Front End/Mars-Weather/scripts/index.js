// Video Links:
//         https://www.youtube.com/watch?v=1-jQfGJibzc     (HTML)
//         https://www.youtube.com/watch?v=LLsrgqnFet0     (CSS)
//         https://www.youtube.com/watch?v=KFKF1baf8mY     (CSS)
//         https://www.youtube.com/watch?v=pcYbAzSfC5I     (CSS)
//         https://www.youtube.com/watch?v=MDENx86nK4k     (JS)

//     Github:
//         https://github.com/kevin-powell/Mars-Weather-App

//     Ditto Copy: Almost (~90)


const API_KEY = 'DEMO_KEY'
const API_URL = `https://api.nasa.gov/insight_weather/?api_key=${API_KEY}&feedtype=json&ver=1.0`


const PREVIOUS_WEATHER = document.querySelector('.previous-weather')
const TOGGLE_PREVIOUS_WEATHER_BTN = document.querySelector('.show-previous-weather-btn')

const UNIT_TOGGLE_BTN = document.querySelector('[data-toggler]')
const METRIC_RADIO = document.getElementById('cel')
const IMPERIAL_RADIO = document.getElementById('fah')

// Current Data Elements
const CURRENT_SOL_ELEMENT = document.querySelector('[data-crnt-sol]')
const CURRENT_DATE = document.querySelector('[data-crnt-date]')
const CURRENT_HIGH_TEMP = document.querySelector('[data-crnt-high-temp]')
const CURRENT_LOW_TEMP = document.querySelector('[data-crnt-low-temp]')
const WIND_SPEED = document.querySelector('[data-wind-speed]')
const WIND_DIRECTION_TEXT = document.querySelector('[data-wind-direction-text]')
const WIND_DIRECTION_ARROW = document.querySelector('[data-wind-direction-arrow')

// Previous Data Elements
const PREVIOUS_SOL_CONTAINER = document.querySelector('[data-previous-sols]')
const PREVIOUS_SOL_TEMPLATE = document.querySelector('[data-previous-sols-template]')

// Previous Sols Toggle
TOGGLE_PREVIOUS_WEATHER_BTN.addEventListener('click', () => {
    PREVIOUS_WEATHER.classList.toggle('show-weather')
})

// --------------------------------------------------------------------

let selectedSolIndex

getWeather().then(sols => {
    selectedSolIndex = sols.length - 1

    displaySelectedSol(sols)
    displayPreviousSols(sols)

    updateUnits()

    METRIC_RADIO.addEventListener('change', () => {
        displaySelectedSol(sols)
        displayPreviousSols(sols)
        updateUnits()
    })
    IMPERIAL_RADIO.addEventListener('change', () => {
        displaySelectedSol(sols)
        displayPreviousSols(sols)
        updateUnits()
    })

    UNIT_TOGGLE_BTN.addEventListener('click', () => {
        let celcius = !isMetric()
        METRIC_RADIO.checked = celcius
        IMPERIAL_RADIO.checked = !celcius

        displaySelectedSol(sols)
        displayPreviousSols(sols)
        updateUnits()
    })
})

function displaySelectedSol(sols) {
    const selectedSol = sols[selectedSolIndex]

    CURRENT_SOL_ELEMENT.innerText = selectedSol.sol
    CURRENT_DATE.innerText = selectedSol.date
    CURRENT_HIGH_TEMP.innerText = convertTemp(selectedSol.maxTemp)
    CURRENT_LOW_TEMP.innerText = convertTemp(selectedSol.minTemp)
    WIND_SPEED.innerText = convertWind(selectedSol.windSpeed)
    WIND_DIRECTION_ARROW.style.setProperty('--direction', `${selectedSol.windDirectionDegrees}deg`)
    WIND_DIRECTION_TEXT.innerText = selectedSol.windDirectionCardinal
}
function displayPreviousSols(sols) {
    PREVIOUS_SOL_CONTAINER.innerHTML = ''

    sols.forEach((solData, i) => {
        const solContainer = PREVIOUS_SOL_TEMPLATE.content.cloneNode(true)
        solContainer.querySelector('[data-sol]').innerText = solData.sol
        solContainer.querySelector('[data-date]').innerText = solData.date
        solContainer.querySelector('[data-temp-high]').innerText = convertTemp(solData.maxTemp)
        solContainer.querySelector('[data-temp-low]').innerText = convertTemp(solData.minTemp)

        solContainer.querySelector('[data-more-info]').addEventListener('click', () => {
            selectedSolIndex = i
            displaySelectedSol(sols)
        })

        PREVIOUS_SOL_CONTAINER.appendChild(solContainer)
    })
}

function getWeather() {
    return fetch(API_URL)
        .then(res => res.json())
        .then(data => {
            const { sol_keys, validity_checks, ...solData } = data

            return Object.entries(solData).map(([sol, data]) => {
                return {
                    sol: sol,
                    maxTemp: data.AT.mx,
                    minTemp: data.AT.mn,
                    windSpeed: data.HWS.av,
                    windDirectionDegrees: data.WD.most_common.compass_degrees,
                    windDirectionCardinal: data.WD.most_common.compass_point,
                    date: new Date(data.First_UTC).toLocaleDateString(
                        undefined,
                        { day: 'numeric', month: 'long' }
                    )
                }
            })
        })
}

function updateUnits() {
    document.querySelectorAll('[data-temp-unit]').forEach(elem => {
        elem.innerText = isMetric() ? 'C' : 'F'
    })
    document.querySelectorAll('[data-speed-unit]').forEach(elem => {
        elem.innerText = isMetric() ? 'Kph' : 'Mph'
    })
}
function isMetric() {
    return METRIC_RADIO.checked
}

function convertTemp(temp) {
    if (isMetric())
        return Math.round(temp)
    return Math.round((temp - 32) * (5 / 9))
}
function convertWind(wind) {
    if (isMetric())
        return Math.round(wind)
    return Math.round(wind / 1.609)
}
