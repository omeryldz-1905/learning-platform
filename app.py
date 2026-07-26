from flask import Flask, render_template, request, jsonify
import os

app = Flask(__name__)
app.config['DEBUG'] = True

# Ana sayfa
@app.route('/')
def index():
    return render_template('index.html')

# Arduino dersleri
@app.route('/arduino/<lesson>')
def arduino_lesson(lesson):
    return render_template(f'arduino/{lesson}.html')

# Python dersleri
@app.route('/python/<lesson>')
def python_lesson(lesson):
    return render_template(f'python/{lesson}.html')

# API: Kod dosyaları
@app.route('/api/code/<path:filepath>')
def get_code(filepath):
    try:
        with open(f'code/{filepath}', 'r', encoding='utf-8') as f:
            return jsonify({'code': f.read()})
    except:
        return jsonify({'error': 'Dosya bulunamadı'}), 404

# API: Hakkında
@app.route('/api/info')
def info():
    return jsonify({
        'name': 'Tech Academy',
        'description': 'Arduino, Python ve 3D Modelleme Öğrenme Platformu',
        'version': '1.0.0'
    })

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)