const net = new brain.NeuralNetwork({
    // hiddenLayers: [4]
})

const trainingData = [
    { input: { r: 0, g: 0, b: 0 }, output: [0] },
    { input: { r: 1, g: 1, b: 1 }, output: [1] }
]
net.train(trainingData)


const COLOR_ELEM = document.getElementById('color')
const GUESS_ELEM = document.getElementById('guess')
const WHITE_BTN = document.getElementById('white-btn')
const BLACK_BTN = document.getElementById('black-btn')
const PRINT_BTN = document.getElementById('print-btn')
let color

document.getElementById('diagram').innerHTML = brain.utilities.toSVG(net)

setRandomColor()
function setRandomColor() {
    color = {
        r: Math.random(),
        g: Math.random(),
        b: Math.random()
    }

    const guess = net.run(color)[0]
    GUESS_ELEM.style.color = guess > .5 ? '#FFF' : '#000'

    COLOR_ELEM.style.background = `rgba(${color.r * 255}, ${color.g * 255}, ${color.b * 255})`
}


WHITE_BTN.addEventListener('click', () => chooseColor(1))
BLACK_BTN.addEventListener('click', () => chooseColor(0))

function chooseColor(value) {
    trainingData.push({
        input: color,
        output: [value]
    })

    setRandomColor()
}

PRINT_BTN.addEventListener('click', () => {
    console.log(JSON.stringify(trainingData))
})