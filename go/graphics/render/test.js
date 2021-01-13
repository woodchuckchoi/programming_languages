var dummy = {"points": [[56,35,102], [264,65,86], [77,423,216]], "edges":[[false,true,true], [true,false,true], [true,true,false]]}

var two = new Two({
    fullscreen: true,
    autostart: true
  }).appendTo(document.body);

var width_centre = two.width / 2;
var height_centre = two.height / 2;

var z_axis = two.makeLine(width_centre, height_centre, width_centre, 0);
var y_axis = two.makeLine(width_centre, height_centre, two.width, height_centre);
var x_axis = two.makeLine(width_centre, height_centre, 0, height_centre + Math.sin(Math.PI/6)*width_centre);

var points = [];
var edges = [];

dummy.points.forEach((vector) => {
    let x = vector[0];
    let y = vector[1];
    let z = vector[2];

    let point = two.makeCircle(width_centre + y - x * Math.cos(Math.PI/6), height_centre - z + x * Math.sin(Math.PI/6), 2);
    points.push(point);
})

dummy.edges.forEach((bools, curIdx) => {
    let from = points[curIdx];
    bools.forEach((pt, ptIdx) => {
        if (ptIdx > curIdx && pt) {
            let to = points[ptIdx];

            let from_x = from._translation._x;
            let from_y = from._translation._y;
            let to_x = to._translation._x;
            let to_y = to._translation._y;

            let line = two.makeLine(from_x, from_y, to_x, to_y);
            edges.push(line);
        }
    })
})

// const x_scroll = (degree) => {
    
// }

// const renderAxes = () => {
//     let z = 
// }

//   var rect = two.makeRectangle(two.width / 2, two.height / 2, 50 ,50);
//   two.bind('update', function() {
//     rect.rotation += 0.001;
//   });