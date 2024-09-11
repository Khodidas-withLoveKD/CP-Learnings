const calculator = {
	finalValue: 0,
	plus: function (val) {
		console.log('kd Plus val:', val)
		this.finalValue += val
		console.log('kd AFTER PLUS this.finalValue:', this.finalValue)
		return this
	},
	minus: function (val) {
		console.log('kd minus val:', val)
		this.finalValue -= val
		console.log('kd AFTER MINUS this.finalValue:', this.finalValue)
		return this
	},
	value: function () {
		console.log('kd this.finalValue:', this.finalValue)
		return this.finalValue
	},
}

function createCalculator() {
	let currentValue = 0

	function plus(val) {
		currentValue += val
		return {
			plus,
			minus,
			value: () => currentValue,
		}
	}

	function minus(val) {
		currentValue -= val
		return {
			plus,
			minus,
			value: () => currentValue,
		}
	}

	return { plus, minus, value: () => currentValue }
}

function plus(val) {
	return createCalculator().plus(val)
}

function minus(val) {
	return calculator.minus(val)
}

// input
function evaluate(cond) {
	switch (cond) {
		case 1:
			return plus(2).plus(3).value() // should return 5
		case 2:
			return plus(3).minus(2).value() // should return 1
		case 3:
			return plus(2).minus(3).value() // should return -1
		case 4:
			return plus(2).plus(3).plus(4).minus(1).minus(3).value() // should return 5
	}
}

for (let i = 1; i < 5; i++) {
	console.log(`case ${i} | ans = `, evaluate(i))
	console.log('--------')
}
// start
// const ans = evaluate(1)
// console.log('ans = ', ans)
