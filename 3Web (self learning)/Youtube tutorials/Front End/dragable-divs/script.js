//  Video Link: https://www.youtube.com/watch?v=jfYWwQrtzzY

const draggables = document.querySelectorAll('.draggable')
const containers = document.querySelectorAll('.container')

draggables.forEach(elem => {
    elem.addEventListener('dragstart', () => {
        elem.classList.add('dragging')
    })

    elem.addEventListener('dragend', () => {
        elem.classList.remove('dragging')
    })
})

containers.forEach(container => {
    container.addEventListener('dragover', e => {
        e.preventDefault()

        const draggingElem = document.querySelector('.dragging')
        const afterElement = getDragAfterElement(container, e.clientY)

        if (afterElement)
            container.insertBefore(draggingElem, afterElement)
        else
            container.appendChild(draggingElem)
    })
})

function getDragAfterElement(container, y) {
    const dragableElements = [...container.querySelectorAll('.draggable:not(.dragging)')]

    return dragableElements.reduce((closest, child) => {
        const box = child.getBoundingClientRect()
        const offset = y - box.top - box.height / 2

        if (offset < 0 && offset > closest.offset)
            return { offset: offset, element: child }
        else
            return closest

    }, { offset: Number.NEGATIVE_INFINITY }).element
}
