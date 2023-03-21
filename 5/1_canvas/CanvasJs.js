let shapeMap = {
    star: [
        {x: 200, y: 50},
        {x: 250, y: 150},
        {x: 350, y: 170},
        {x: 280, y: 250},
        {x: 300, y: 350},
        {x: 200, y: 300},
        {x: 100, y: 350},
        {x: 120, y: 250},
        {x: 50, y: 170},
        {x: 150, y: 150},
        {x: 200, y: 50}
      ],
    home: [
        {x: 100, y: 300},
        {x: 100, y: 200},
        {x: 200, y: 100},
        {x: 300, y: 200},
        {x: 300, y: 300},
        {x: 100, y: 300},

      ],
    sand_watch: [
        {x: 100, y: 100},
        {x: 300, y: 300},
        {x: 100, y: 300},
        {x: 300, y: 100},
        {x: 100, y: 100},
      ]
}

let shapeNames = Object.keys(shapeMap);

function getCoordinatesByIndex(index) {
    return shapeMap[shapeNames[index]];
}
