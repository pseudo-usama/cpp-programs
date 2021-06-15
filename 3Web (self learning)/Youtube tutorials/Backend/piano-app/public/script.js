let recordingStartTime
let songNotes
if (typeof(currentSong) !== 'undefined') {
    songNotes = currentSong.notes
}


const WHITE_KEYS = ['z', 'x', 'c', 'v', 'b', 'n', 'm']
const BLACK_KEYS = ['s', 'd', 'g', 'h', 'j']


const RECORD_BTN = document.querySelector('.record-btn')
const PLAY_BTN = document.querySelector('.play-btn')
const SAVE_BTN = document.querySelector('.save-btn')
const SONG_LINK = document.querySelector('.song-link')

RECORD_BTN && RECORD_BTN.addEventListener('click', toggleRecording)
PLAY_BTN.addEventListener('click', playSong)
SAVE_BTN && SAVE_BTN.addEventListener('click', saveSong)


const KEYS = document.querySelectorAll('.key')
const WHITE_KEYS_ELEMS = document.querySelectorAll('.key.white')
const BLACK_KEYS_ELEMS = document.querySelectorAll('.key.black')

const KEY_MAP = [...KEYS].reduce((map, key) => {
    map[key.dataset.note] = key
    return map
}, {})

KEYS.forEach(key => {
    key.addEventListener('click', () => playNote(key))
})

document.addEventListener('keydown', e => {
    if (e.repeat) return
    const key = e.key
    const whiteKeyIndex = WHITE_KEYS.indexOf(key)
    const blackKeyIndex = BLACK_KEYS.indexOf(key)

    if (whiteKeyIndex > -1) playNote(WHITE_KEYS_ELEMS[whiteKeyIndex])
    if (blackKeyIndex > -1) playNote(BLACK_KEYS_ELEMS[blackKeyIndex])
})

function playNote(key) {
    if (isRecording()) {
        recordNote(key.dataset.note)
    }

    const noteAudio = document.getElementById(key.dataset.note)
    noteAudio.currentTime = 0
    noteAudio.play()
    key.classList.add('active')
    noteAudio.addEventListener('ended', () => {
        key.classList.remove('active')
    })
}
function recordNote(note) {
    songNotes.push({
        key: note,
        startTime: Date.now() - recordingStartTime
    })
}

function toggleRecording() {
    RECORD_BTN.classList.toggle('active')

    if (isRecording()) startRecording()
    else/************/ stoprecording()
}

function isRecording() {
    return RECORD_BTN !== null && RECORD_BTN.classList.contains('active')
}
function startRecording() {
    recordingStartTime = Date.now()
    songNotes = []

    PLAY_BTN.classList.remove('show')
    SAVE_BTN.classList.remove('show')
}
function stoprecording() {
    playSong()
    if (songNotes.length !== 0) {
        PLAY_BTN.classList.add('show')
        SAVE_BTN.classList.add('show')
    }
}
function playSong() {
    if (songNotes.length === 0)
        return
    songNotes.forEach(note => {
        setTimeout(() => {
            playNote(KEY_MAP[note.key])
        }, note.startTime)
    })
}

function saveSong() {
    axios.post('/songs', { songNotes: songNotes })
        .then(res => {
            SONG_LINK.classList.add('show')
            SONG_LINK.href = `/songs/${res.data._id}`
        })
}
